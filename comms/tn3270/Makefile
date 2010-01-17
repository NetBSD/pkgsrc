# $NetBSD: Makefile,v 1.1.1.1 2010/01/17 02:14:51 dholland Exp $

DISTNAME=	tn3270-0.20100116
CATEGORIES=	comms net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Utilities for connecting to IBM VM/CMS systems

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin share/tn3270

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
