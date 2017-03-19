# $NetBSD: Makefile,v 1.36 2017/03/19 16:31:43 gdt Exp $

# gpsd 3.11 has been released.  It has only not been updated because
# newer versions use scons.
DISTNAME=	gpsd-2.96
PKGREVISION=	6
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/gpsd
COMMENT=	GPS information daemon

LICENSE=	modified-bsd

# XXX: In theory this is not necessary.
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.96

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++

# gpsd looks for ncurses but not curses. (Not yet filed upstream.)
FAKE_NCURSES=	yes

# gpsd uses syncok (which at least NetBSD curses lacks).
USE_CURSES+=	syncok
# However, syncok isn't tested in mk/curses.builtin.mk.  For now, test
# another feature that NetBSD curses lacks.
USE_CURSES+=	getsyx

CFLAGS.SunOS=	-DLOG_PERROR=0

INSTALLATION_DIRS=	sbin

TEST_TARGET=	check

.include "../../lang/python/extension.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
