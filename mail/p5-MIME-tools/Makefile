# $NetBSD: Makefile,v 1.30 2007/11/29 15:13:06 wiz Exp $
#

DISTNAME=	MIME-tools-5.425
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mit
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-tools/
COMMENT=	Perl5 modules for encoding and decoding MIME messages

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Temp>=0.17:../../devel/p5-File-Temp
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64>=3.03:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME-tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
