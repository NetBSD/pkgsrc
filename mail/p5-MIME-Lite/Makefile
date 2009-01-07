# $NetBSD: Makefile,v 1.14.2.1 2009/01/07 11:38:44 rtr Exp $

DISTNAME=	MIME-Lite-3.023
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5mil
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MMIME-Lite/
COMMENT=	Perl5 module for simple creation of MIME email messages

DEPENDS+=	p5-Email-Date-Format>=1.0:../../mail/p5-Email-Date-Format
DEPENDS+=	p5-MailTools>=1.62:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-Base64>0:../../converters/p5-MIME-Base64
# MIME::QuotedPrint is part of p5-MIME-Base64 package
DEPENDS+=	p5-MIME-Types>=1.13:../../mail/p5-MIME-Types

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
