# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 16:31:27 jlam Exp $

DISTNAME=	cyrus-imapd-mod-1.4.3
PKGNAME=	wbm-${DISTNAME:S/-mod-/-/}
MASTER_SITES=	http://www.tecchio.net/webmin/cyrus/

DEPENDS+=	cyrus-imapd>=2.1:../../mail/cyrus-imapd
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Mail-IMAPClient-[0-9]*:../../mail/p5-Mail-IMAPClient

HOMEPAGE=	http://www.tecchio.net/webmin/cyrus/
COMMENT=	Webmin module for administering Cyrus IMAP

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
