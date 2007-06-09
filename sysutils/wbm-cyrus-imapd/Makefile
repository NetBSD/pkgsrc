# $NetBSD: Makefile,v 1.5 2007/06/09 23:02:41 joerg Exp $

DISTNAME=	cyrus-imapd-mod-1.6
WBM_NAME=	cyrus-imapd
PKGNAME=	wbm-${DISTNAME:S/-mod-/-/}
MASTER_SITES=	http://www.tecchio.net/webmin/cyrus/

DEPENDS+=	cyrus-imapd>=2.1:../../mail/cyrus-imapd
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Mail-IMAPClient-[0-9]*:../../mail/p5-Mail-IMAPClient
DEPENDS+=	p5-Tree-Simple-[0-9]*:../../devel/p5-Tree-Simple

HOMEPAGE=	http://www.tecchio.net/webmin/cyrus/
COMMENT=	Webmin module for administering Cyrus IMAP

WBM_STD_MODULE=	NO

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
