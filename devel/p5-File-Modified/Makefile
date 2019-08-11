# $NetBSD: Makefile,v 1.20 2019/08/11 13:19:27 wiz Exp $

DISTNAME=	File-Modified-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Modified
COMMENT=	Perl module for checking intelligently if files have changed
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.6.1,p5-File-Temp>=0}:../../devel/p5-File-Temp
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=0}:../../security/p5-Digest-MD5

PERL5_PACKLIST=		auto/File/Modified/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
