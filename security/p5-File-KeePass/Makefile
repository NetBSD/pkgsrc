# $NetBSD: Makefile,v 1.7 2018/08/22 09:46:26 wiz Exp $

DISTNAME=	File-KeePass-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-KeePass/
COMMENT=	Perl module interface to KeePass V1 and V2 database files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/File/KeePass/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
