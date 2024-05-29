# $NetBSD: Makefile,v 1.45 2024/05/29 16:34:13 adam Exp $
#

DISTNAME=	dirb220
PKGNAME=	dirb-2.20
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dirb
USE_TOOLS+=	pax chmod

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	share/wordlists/dirb

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

post-extract:
	# Work around broken permissions in archive file, all mode 000
	${CHMOD} -R 755 ${WRKSRC}
	${FIND} ${WRKSRC}/wordlists -type f -print | ${XARGS} ${CHMOD} 644

post-install:
	cd ${WRKSRC}/wordlists && ${PAX} -rw * ${DESTDIR}${PREFIX}/share/wordlists/dirb

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
