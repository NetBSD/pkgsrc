# $NetBSD: Makefile,v 1.4 2001/11/28 05:20:41 jlam Exp $

DISTNAME=	gtkyahoo-0.18.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkyahoo/} \
		http://www.unixtools.org/gtkyahoo/dist/

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://www.unixtools.org/gtkyahoo/
COMMENT=	GTK+ client for Yahoo! Messenger

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libyahoo="${BUILDLINK_DIR}"

pre-configure:
	${RM} -rf ${WRKSRC}/libyahoo

.include "../../chat/libyahoo/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
