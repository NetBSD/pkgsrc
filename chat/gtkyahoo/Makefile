# $NetBSD: Makefile,v 1.2 2001/10/23 13:14:47 jlam Exp $

DISTNAME=	gtkyahoo-0.18.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkyahoo/} \
		http://www.unixtools.org/gtkyahoo/dist/

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://www.unixtools.org/gtkyahoo/
COMMENT=	GTK+ client for Yahoo! Messenger

BUILD_DEPENDS+=		bison:../../devel/bison

USE_BUILDLINK_ONLY=	YES
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libyahoo="${BUILDLINK_DIR}"

pre-configure:
	${RM} -rf ${WRKSRC}/libyahoo

.include "../../mk/x11.buildlink.mk"
.include "../../chat/libyahoo/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
