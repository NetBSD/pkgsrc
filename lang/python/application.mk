# $NetBSD: application.mk,v 1.4 2004/01/14 02:10:47 xtraeme Exp $

.include "../../lang/python/pyversion.mk"

# replace shell magic by python version specific path
# PYTHON_PATCH_SCRIPTS is a list of Python scripts to be installed,
#  relative to ${WRKSRC}

_PYTHON_PATCH_SCRIPT_SED=	-e "1s;^\#!.*python[^ ];\#!${PYTHONBIN};"
_PYTHON_PATCH_SCRIPT_SED+=	${PYTHON_PATCH_SCRIPT_SED}

.if defined(PYTHON_PATCH_SCRIPTS)
python-patch-scripts:
.for FILE in ${PYTHON_PATCH_SCRIPTS}
	cd ${WRKSRC}; for file in ${FILE}; do				\
		${SED} ${_PYTHON_PATCH_SCRIPT_SED}			\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done
.endfor

post-patch: python-patch-scripts
.endif
