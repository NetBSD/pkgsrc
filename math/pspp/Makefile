# $NetBSD: Makefile,v 1.13 2001/02/05 09:01:00 tron Exp $
#

DISTNAME=	pspp-0.3.0
CATEGORIES=	math
MASTER_SITES=	ftp://franz.stat.wisc.edu/pub/PSPP/ \
		ftp://alpha.gnu.org/gnu/pspp/ \
		ftp://ftp.gwdg.de/pub/gnu-alpha/pspp/ \
		ftp://ftp.unex.es/pub/gnu-beta/pspp/ \
		ftp://ftp.cs.columbia.edu/.archives/gnu/alpha/pspp/ \
		ftp://ftp.kddlabs.co.jp/.1/alpha-gnu/pspp/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/gnu-alpha/pspp/ \
		ftp://ftp.tuniv.szczecin.pl/mirrors/alpha.gnu.org/pub/gnu/pspp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pspp/

BUILD_DEPENDS+=	${LOCALBASE}/bin/${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
USE_LIBINTL=	yes
CPPFLAGS+=	-Dunix=1
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=	pkgsysconfdir="${PREFIX}/etc/pspp"

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
