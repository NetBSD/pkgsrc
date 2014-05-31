# $NetBSD: modules.mk,v 1.1 2014/05/31 14:22:38 obache Exp $
#
# This Makefile fragment is intended to be included by packages that install
# UIM modules.  It takes care of update the corresponding databases
# at (de)installation time.
#
# The following variables can be defined:
#    UIM_MODULES - Set to list of UIM module names installed by the package.

.if !defined(UIM_MODULES_MK)
UIM_MODULES_MK=	# defined

.if (defined(UIM_MODULES) && !empty(UIM_MODULES)) || defined(_BUILDING_UIM)

.  if defined(_BUILDING_UIM)
BUILDLINK_PREFIX.uim=	${PREFIX}
.  else
EVAL_PREFIX+=	BUILDLINK_PREFIX.uim=uim
DEPENDS+=	uim-[0-9]*:../../inputmethod/uim
.  endif

UIM_MODULE_MANAGER=	${BUILDLINK_PREFIX.uim}/bin/uim-module-manager
UIM_MODULE_LIST_DIR=	${BUILDLINK_PREFIX.uim}/share/uim/pkgsrc

FILES_SUBST+=		UIM_MODULE_MANAGER=${UIM_MODULE_MANAGER:Q}
FILES_SUBST+=		UIM_MODULE_LIST_DIR=${UIM_MODULE_LIST_DIR:Q}
FILES_SUBST+=		UIM_MODULES=${UIM_MODULES:Q}
INSTALL_TEMPLATES+=	../../inputmethod/uim/files/modules.tmpl
DEINSTALL_TEMPLATES+=	../../inputmethod/uim/files/modules.tmpl

GENERATE_PLIST+=	for m in ${UIM_MODULES}; do \
			echo ${UIM_MODULE_LIST_DIR:S,^${BUILDLINK_PREFIX.uim}/,,}/$${m}; \
			done

post-install: uim-add-module-names
uim-add-module-names: .PHONY 
	${INSTALL_DATA_DIR} ${DESTDIR}${UIM_MODULE_LIST_DIR}
	${RUN}cd ${DESTDIR}${UIM_MODULE_LIST_DIR};		\
		for m in ${UIM_MODULES}; do			\
			${INSTALL_DATA} /dev/null $${m};	\
		done

.endif

TOOLS_NOOP+=		uim-module-manager

.endif			# UIM_MODULES_MK
