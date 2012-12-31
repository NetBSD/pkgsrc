# $NetBSD: Makefile,v 1.43 2012/12/31 00:27:37 sbd Exp $
#

DISTNAME=	sed-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		YES
TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# at least Solaris-2.9 has issues with grep/egrep
USE_TOOLS+=		grep makeinfo

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"

post-install:
.for g n in bin/gsed ${PKGGNUDIR}bin/sed ${PKGMANDIR}/man1/gsed.1 ${PKGGNUDIR}${PKGMANDIR}/man1/sed.1
	${LN} -sf ${PREFIX}/${g} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
