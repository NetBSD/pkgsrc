# $NetBSD: Makefile,v 1.7 2005/04/28 23:17:53 jlam Exp $
#

DISTNAME=		sge-5.3p6
PKGREVISION=	2
CATEGORIES=		parallel sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gridengine.sunsource.net/
COMMENT=		Sun Grid Engine distributed resource management system

BUILD_DEPENDS+=		{standalone-tcsh,tcsh}-[0-9]*:../../shells/tcsh

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_PERL5=		YES

CFLAGS+=		-D${UPPER_OPSYS}
CONFIGURE_ENV+=		REMOTE=sge
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--with-grd=${SGE_BUILDARCH}
PLIST_SUBST+=		SGE_ARCH=${SGE_ARCH}
MESSAGE_SUBST+=		SGE_ROOT=${SGE_ROOT}
MAKE_ENV+=		PERL5=${PERL5}

USE_PKGINSTALL=		YES
SGE_USER?=		sgeadmin
SGE_GROUP?=		sgeadmin
PKG_GROUPS=		${SGE_GROUP}
PKG_USERS=		${SGE_USER}:${SGE_GROUP}::Sun\\ Grid\\ Engine\\ Administrator

EVAL_PREFIX+=	PKGSRC_SSL_PREFIX=openssl

AIMK=	${SETENV} ${MAKE_ENV} tcsh -fb ${WRKSRC}/source/aimk

CONFIG_GUESS_OVERRIDE=	source/3rdparty/qmake/config.guess \
		source/3rdparty/qtcsh/config.guess
CONFIG_SUB_OVERRIDE=	source/3rdparty/qmake/config.sub \
		source/3rdparty/qtcsh/config.sub

.include "../../mk/bsd.prefs.mk"

# SGE_ARCH should match the putput of ${WRKSRC}/source/dist/util/arch
# SGE_BUILDARCH should match whats in ${WRKSRC}/source/aimk
UPPER_OPSYS_cmd=	${ECHO} "${OPSYS}" | ${TR} a-z A-Z
UPPER_OPSYS=		${UPPER_OPSYS_cmd:sh}

.if ${OPSYS} == "NetBSD"
SGE_ARCH=		nbsd-${MACHINE_ARCH}
SGE_BUILDARCH_cmd=	${ECHO} "${OPSYS}_${MACHINE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "FreeBSD"
SGE_ARCH=		fbsd-${MACHINE_ARCH}
SGE_BUILDARCH_cmd=	${ECHO} "${OPSYS}_${MACHINE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "SunOS"
.  if ${MACHINE_ARCH} == "i386"
SGE_ARCH=		solaris86
.  else
_ISAINFO!=		isainfo
.    if !empty(_ISAINFO:Msparcv9)
SGE_ARCH=		solaris64
.    else
SGE_ARCH=		solaris
.    endif
.  endif
SGE_BUILDARCH_cmd=	${ECHO} "${SGE_ARCH}" | ${TR} a-z A-Z
.elif ${OPSYS} == "Darwin"
SGE_ARCH=		darwin
SGE_BUILDARCH=		DARWIN
.else
PKG_FAIL_REASON=	"SGE_ARCH and SGE_BUILDARCH need to be confgured for your OS"
.endif
SGE_BUILDARCH?=		${SGE_BUILDARCH_cmd:sh}

LDFLAGS+=	-R${SGE_ROOT}/lib/${SGE_ARCH}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${SGE_ROOT}/lib/${SGE_ARCH}

SGE_ROOT=	${PREFIX}/sge

post-patch:
	@if [ "`${WRKSRC}/source/dist/util/arch`" != "${SGE_ARCH}" ]; then \
		${ECHO} "ERROR:  SGE_ARCH as set in the pkgsrc Makefile," ;\
		${ECHO} "        ${SGE_ARCH}, does not agree with that returned by" ; \
		${ECHO} "        ${WRKSRC}/source/dist/util/arch," ; \
		${ECHO} "        `${WRKSRC}/source/dist/util/arch`" ; \
		${FALSE} ; \
	fi

pre-configure:
.for __tmp__ in source/dist/util/arch_variables source/scripts/distinst.site source/aimk.site
	${MV} ${WRKSRC}/${__tmp__} ${WRKSRC}/${__tmp__}.bak
	${SED} -e 's;@rcd_dir@;${RCD_SCRIPTS_DIR};g' -e 's;@ssl_prefix@;${SSL_PREFIX};g' \
		-e 's;@perl5@;${PERL5};g' ${WRKSRC}/${__tmp__}.bak > \
		${WRKSRC}/${__tmp__}
	${RM} ${WRKSRC}/${__tmp__}.bak
.endfor

do-configure:
.for __prog__ in qmake qtcsh
	${MKDIR} ${WRKSRC}/source/3rdparty/${__prog__}/${SGE_BUILDARCH}
	cd ${WRKSRC}/source/3rdparty/${__prog__}/${SGE_BUILDARCH} && \
		${SETENV} ${CONFIGURE_ENV} \
		SGE_ARCH=`${WRKSRC}/source/dist/util/arch` \
		../configure ${CONFIGURE_ARGS} --srcdir=..
.endfor

do-build:
	cd ${WRKSRC}/source && ${AIMK} -only-depend
	cd ${WRKSRC}/source && ${SETENV} ${MAKE_ENV} ./scripts/zerodepend
	cd ${WRKSRC}/source && ${AIMK} -no-qmake -no-qtcsh depend
	cd ${WRKSRC}/source && ${AIMK} -secure
	cd ${WRKSRC}/source && ${AIMK} -man

do-install:
	${LN} -fs ${WRKSRC}/source/scripts/distinst ${WRKSRC}/source/scripts/myinst
	${MKDIR} ${SGE_ROOT}
	${CHOWN} ${SGE_USER} ${SGE_ROOT}
	${CHGRP} ${SGE_GROUP} ${SGE_ROOT}
	cd ${WRKSRC}/source && \
		${ECHO} "Y" | ${SETENV} LOCALBASE=${LOCALBASE} SGE_ROOT=${SGE_ROOT} ./scripts/myinst -allall ${SGE_ARCH}
	cd ${SGE_ROOT} && ${SETENV} SGE_ROOT=${SGE_ROOT} ./util/setfileperm.sh -auto -noresport \
		${SGE_USER} ${SGE_GROUP} ${SGE_ROOT}
	for f in ${SGE_ROOT}/bin/${SGE_ARCH}/q* ; do \
		cd ${PREFIX}/bin && ${LN} -fs $$f ; done

.include "../../graphics/xpm/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
.if ${USE_BUILTIN.openssl} == "yes"
SSL_PREFIX=	/usr
.else
SSL_PREFIX=	${PKGSRC_SSL_PREFIX}
.endif
