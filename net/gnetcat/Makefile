# $NetBSD: Makefile,v 1.12 2014/06/03 07:11:52 obache Exp $

DISTNAME=	netcat-0.7.1
PKGNAME=	gnetcat-0.7.1
PKGREVISION=	3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netcat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://netcat.sourceforge.net/
COMMENT=	Read and write data across network connections

GNU_CONFIGURE=		YES
INFO_FILES=		yes
USE_TOOLS+=		msgfmt makeinfo

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
