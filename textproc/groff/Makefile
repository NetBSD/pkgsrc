# $NetBSD: Makefile,v 1.22 2005/01/18 12:54:59 tv Exp $
#

DISTNAME=	groff-1.19.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

DEPENDS+=	netpbm>=10.0:../../graphics/netpbm
DEPENDS+=	psutils>=1.17:../../print/psutils

NOT_FOR_PLATFORM= Interix-*-* # endless loop in build

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_PERL5=		YES
USE_BUILDLINK3=		YES

INFO_FILES=	groff

.include "../../mk/bsd.prefs.mk"

.ifdef PAPERSIZE
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

# Usually the mdoc.local "volume-operating-system" definition is for
# the operating system name often displayed on top of man pages. And
# "operating-system" is for the default .Os value (operating system
# and version/release) and is usually displayed at bottom of man page.
# XXX Use "pkgsrc" as default .Os value.
post-patch:
	${SED}	-e "s,@@VOLUME_OPERATING_SYSTEM@@,${OPSYS},g"	\
		-e "s,@@OPERATING_SYSTEM@@,pkgsrc,g"	\
		${FILESDIR}/mdoc.local > ${WRKDIR}/mdoc.local

post-install:
	${INSTALL_DATA} ${WRKDIR}/mdoc.local \
		${PREFIX}/share/groff/site-tmac

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
