# $NetBSD: Makefile,v 1.21 2002/10/21 15:44:13 wiz Exp $
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
COMMENT=	Program for statistical analysis of sampled data

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-Dunix=1
MAKE_ENV+=	pkgsysconfdir="${PREFIX}/etc/pspp"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
