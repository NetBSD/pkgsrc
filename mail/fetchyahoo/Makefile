# $NetBSD: Makefile,v 1.18 2020/03/20 11:57:57 nia Exp $
#

DISTNAME=		fetchyahoo-2.11.0
PKGREVISION=		8
CATEGORIES=		mail
MASTER_SITES=		http://fetchyahoo.sourceforge.net/
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fetchyahoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fetchyahoo.sourceforge.net/
#HOMEPAGE=		http://fetchyahoo.twizzler.org
COMMENT=		Download mails from Yahoo webmail into mbox

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
#DEPENDS+=		{perl>=5.10,p5-Net-[0-9]*}:../../net/p5-Net
DEPENDS+=		p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_TOOLS+=		perl:run
REPLACE_PERL=		fetchyahoo

NO_BUILD=		yes

EGDIR=			${PREFIX}/share/examples/fetchyahoo
DOCDIR=			${PREFIX}/share/doc/fetchyahoo

CONF_FILES=		${EGDIR}/fetchyahoorc ${PKG_SYSCONFDIR}/fetchyahoorc

SUBST_CLASSES+=		sa2
SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	fetchyahoo fetchyahoo.1 INSTALL
SUBST_SED.sa2=		-e s!/etc/fetchyahoorc!${PKG_SYSCONFDIR}/fetchyahoorc!g
SUBST_SED.sa2+=		-e s!/usr/share/doc/fetchyahoo!${DOCDIR}!g

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/fetchyahoo \
			share/examples/fetchyahoo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fetchyahoo ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fetchyahoo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for i in COPYING ChangeLog Credits INSTALL TODO index.html
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/fetchyahoo
.endfor
	${INSTALL_DATA} ${WRKSRC}/fetchyahoorc ${DESTDIR}${PREFIX}/share/examples/fetchyahoo

.include "../../mk/bsd.pkg.mk"
