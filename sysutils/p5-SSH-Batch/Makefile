# $NetBSD: Makefile,v 1.1.1.1 2009/05/17 20:08:17 seb Exp $

DISTNAME=	SSH-Batch-0.021
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGENT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SSH-Batch/
COMMENT=	Cluster operations based on parallel SSH, set and interval arithmetic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/SSH/Batch/.packlist

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty
DEPENDS+=	p5-Net-OpenSSH>=0.34:../../security/p5-Net-OpenSSH
DEPENDS+=	p5-Set-Scalar>=1.23:../../devel/p5-Set-Scalar
DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey

BUILD_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
