# $NetBSD: Makefile,v 1.4 2004/01/29 13:14:47 grant Exp $
# FreeBSD Id: ports/archivers/xpk/Makefile,v 1.7 2002/10/18 07:58:00 adamw Exp

DISTNAME=	xpk-0.1.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.jormas.com/~vesuri/xpk/ \
		http://energyhq.homeip.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jormas.com/~vesuri/xpk/
COMMENT=	The eXternal PacKer (XPK) library system

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
