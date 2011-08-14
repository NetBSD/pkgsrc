# $NetBSD: Makefile,v 1.5 2011/08/14 13:25:24 obache Exp $
#

DISTNAME=	IMAP-Client-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for IMAP manipulation

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI-imap>=0:../../mail/p5-URI-imap
DEPENDS+=	p5-URI>=0:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IMAP/Client/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
