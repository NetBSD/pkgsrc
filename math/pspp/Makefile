# $NetBSD: Makefile,v 1.10 2000/04/16 08:56:15 mycroft Exp $
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

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=	gettext-0.10.*:../../devel/gettext

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CPPFLAGS+=	-Dunix=1
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=	pkgsysconfdir="${PREFIX}/etc/pspp"

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
