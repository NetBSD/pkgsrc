# $NetBSD: Makefile,v 1.36 2006/03/12 16:26:09 rillig Exp $
#

DISTNAME=	groff-1.19.2
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

DEPENDS+=	netpbm>=10.0:../../graphics/netpbm
DEPENDS+=	psutils>=1.17:../../print/psutils

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERLPATH=${PERL5:Q}
USE_TOOLS+=		gs:run perl:run sed:run

INFO_FILES=	groff

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	.*/sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed+=	font/devps/generate/symbol.sed

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	GNU_PREFIX="g"
.else
PLIST_SUBST+=	GNU_PREFIX=""
.endif

.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE:Q}
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

.include "../../mk/bsd.pkg.mk"
