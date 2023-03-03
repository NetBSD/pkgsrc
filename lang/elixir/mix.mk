# $NetBSD: mix.mk,v 1.3 2023/03/03 10:09:58 wiz Exp $
#
# Common logic that can be used by packages that use mix as a build tool.
#
# Inspired by elixir.mk from FreeBSD ports.
#
# It is not yet fully tested.
# Should packages set HEX_HOME and HOME on their own?
# See devel/hex for an example.

DEPENDS+=		elixir>=1.14.0:../../lang/elixir

ELIXIR_APP_NAME?=	${PKGBASE}
ELIXIR_LIB_ROOT?=	${DESTDIR}${PREFIX}/lib/elixir/lib
ELIXIR_APP_ROOT?=	${ELIXIR_LIB_ROOT}/${ELIXIR_APP_NAME}
ELIXIR_APP_VERSION?=	${PKGVERSION_NOREV}
ELIXIR_HIDDEN?=		"^${ELIXIR_APP_NAME}$$"
ELIXIR_LOCALE?=		en_US.UTF-8

MIX_CMD?=		${PREFIX}/bin/mix
MIX_REWRITE?=
MIX_BUILD_DEPS?=
MIX_RUN_DEPS?=
MIX_DOC_DIRS?=
MIX_DOC_FILES?=
MIX_ENV?=
MIX_ENV+=		HEX_OFFLINE="1"
MIX_ENV+=		HEX_HOME="${WRKSRC}/.home"
MIX_ENV+=		HOME=${WRKSRC}/_build
MIX_ENV_NAME?=		prod
MIX_BUILD_NAME?=	prod
MIX_TARGET?=		compile
MIX_EXTRA_APPS?=
MIX_EXTRA_DIRS?=
MIX_EXTRA_FILES?=
MIX_COMPILE?=		${SETENV} ${MIX_ENV} LANG=${ELIXIR_LOCALE} LC_ALL=${ELIXIR_LOCALE} MIX_ENV=${MIX_ENV_NAME} ELIXIR_HIDDEN=${ELIXIR_HIDDEN} ${MIX_CMD} ${MIX_TARGET}

.if !target(do-build)
do-build: do-mix-build
.endif

.PHONY: do-mix-build
do-mix-build:
	${RM} ${WRKSRC}/mix.lock
	cd ${WRKSRC} && ${MIX_COMPILE}
.for app in ${MIX_EXTRA_APPS}
	${RM} ${WRKSRC}/${app}/mix.lock
	cd ${WRKSRC}/${app} && ${MIX_COMPILE}
.endfor

.if !target(do-install)
do-install: do-mix-install
.endif

do-mix-install:
	${MKDIR} ${ELIXIR_APP_ROOT}/lib
	cd ${WRKSRC}/lib && ${CP} -R * ${ELIXIR_APP_ROOT}/lib
	${MKDIR} ${ELIXIR_APP_ROOT}/ebin
	if test -d ${WRKSRC}/_build/.mix/archives; then \
		${INSTALL_DATA} ${WRKSRC}/_build/.mix/archives/${ELIXIR_APP_NAME}-${ELIXIR_APP_VERSION}/${ELIXIR_APP_NAME}-${ELIXIR_APP_VERSION}/ebin/* \
			${ELIXIR_APP_ROOT}/ebin; \
	fi
	if test -d ${WRKSRC}/_build/${MIX_BUILD_NAME}; then \
		${INSTALL_DATA} ${WRKSRC}/_build/${MIX_BUILD_NAME}/lib/${ELIXIR_APP_NAME}/ebin/* \
			${ELIXIR_APP_ROOT}/ebin; \
	fi
	if test -d ${WRKSRC}/priv; then \
		${MKDIR} ${ELIXIR_APP_ROOT}/priv; \
		cd ${WRKSRC}/priv && ${CP} -R * ${ELIXIR_APP_ROOT}/priv; \
	fi
.if ${MIX_DOC_FILES} != "" || ${MIX_DOC_DIRS} != ""
	${MKDIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/
.endif
.for file in ${MIX_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/
.endfor
.for dir in ${MIX_DOC_DIRS}
	cd ${WRKSRC} && ${CP} -R ${dir} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/
.endfor
.for file in ${MIX_EXTRA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${ELIXIR_APP_ROOT}
.endfor
.for dir in ${MIX_EXTRA_DIRS}
	${MKDIR} ${ELIXIR_APP_ROOT}/${dir}
	cd ${WRKSRC}/${dir} && ${CP} -R . ${ELIXIR_APP_ROOT}/${dir}
.endfor
.for app in ${MIX_EXTRA_APPS}
	${INSTALL_DATA} ${WRKSRC}/${app}/_build/${MIX_BUILD_NAME}/lib/*/ebin/* \
		${ELIXIR_APP_ROOT}/ebin
.endfor
