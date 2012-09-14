# $NetBSD: Makefile,v 1.3 2012/09/14 17:03:58 jakllsch Exp $
#

DISTNAME=	audiotools-2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISON=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiotools/2.18/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://audiotools.sourceforge.net/
COMMENT=	Collection of command line audio handling programs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	25

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	audiotools/*.py
REPLACE_FILES.python+=	audiotools/py_decoders/*.py
REPLACE_FILES.python+=	audiotools/py_encoders/*.py

REPLACE_INTERPRETER+=	bin-python
REPLACE.bin-python.old=	/usr/bin/bin
REPLACE.bin-python.new=	${PYTHONBIN}
REPLACE_FILES.bin-python=	audiotools/player.py

EGG_NAME=	Python_Audio_Tools-${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

.include "../../lang/python/distutils.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
