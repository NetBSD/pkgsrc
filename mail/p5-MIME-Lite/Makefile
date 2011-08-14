# $NetBSD: Makefile,v 1.21 2011/08/14 13:25:25 obache Exp $

DISTNAME=	MIME-Lite-3.027
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mil
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Lite/
COMMENT=	Perl5 module for simple creation of MIME email messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Date-Format>=1.0:../../mail/p5-Email-Date-Format
DEPENDS+=	p5-MailTools>=1.62:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-Base64>0:../../converters/p5-MIME-Base64
# MIME::QuotedPrint is part of p5-MIME-Base64 package
DEPENDS+=	p5-MIME-Types>=1.28:../../mail/p5-MIME-Types

PKG_DESTDIR_SUPPORT=	user-destdir

# Get rid of nasty interactive bits
MAKE_PARAMS+=	</dev/null

PERL5_PACKLIST=		auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
