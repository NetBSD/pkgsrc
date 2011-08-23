# $NetBSD: Makefile,v 1.28 2011/08/23 13:06:48 obache Exp $
#

PKGNAME=	${PYPKGPREFIX}-gdbm-0
PKGREVISION=	4
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html
COMMENT=	Python interface to gdbm - GNU database manager

PKG_DESTDIR_SUPPORT=	user-destdir

EVAL_PREFIX+=	GDBMDIR=gdbm

USE_TOOLS+=	patch

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/gdbmmodule.c
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST+= GDBMPREFIX=${GDBMDIR}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e;								\
	cd ${WRKSRC};							\
	for f in ${PATCHDIR}/patch-*; do				\
		${PATCH} --batch < "$$f" || ${TRUE};			\
	done

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
