# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:02 tv Exp $

DISTNAME=	wol-0.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
INFO_FILES=		wol.info
USE_PERL5=		build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
