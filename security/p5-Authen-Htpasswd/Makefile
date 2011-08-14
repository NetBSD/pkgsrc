# $NetBSD: Makefile,v 1.3 2011/08/14 14:42:46 obache Exp $
#

DISTNAME=	Authen-Htpasswd-0.161
PKGNAME=	p5-${DISTNAME:S/161/16.1/}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-Htpasswd/
COMMENT=	Interface to read and modify Apache .htpasswd files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Authen/Htpasswd/.packlist

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Crypt-PasswdMD5-[0-9]*:../../security/p5-Crypt-PasswdMD5
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-IO-LockedFile-[0-9]*:../../devel/p5-IO-LockedFile

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
