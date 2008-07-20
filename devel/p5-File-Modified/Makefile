# $NetBSD: Makefile,v 1.3 2008/07/20 16:09:34 heinz Exp $

DISTNAME=	File-Modified-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Modified/
COMMENT=	Perl module for checking intelligently if files have changed

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	{perl>=5.6.1,p5-File-Temp>=0}:../../devel/p5-File-Temp
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Digest-MD5>=0:../../security/p5-Digest-MD5

PERL5_PACKLIST=	auto/File/Modified/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
