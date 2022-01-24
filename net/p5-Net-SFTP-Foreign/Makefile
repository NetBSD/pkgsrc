# $NetBSD: Makefile,v 1.7 2022/01/24 16:24:27 gdt Exp $

DISTNAME=	Net-SFTP-Foreign-1.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

# The upstream sources do not have tags for the various versions, and
# upstream doesn't think that's a bug:
#   https://github.com/salva/p5-Net-SFTP-Foreign/issues/14
# Content that belongs in NEWS is available in "Changes" and at:
#   https://metacpan.org/dist/Net-SFTP-Foreign/changes
MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/salva/p5-Net-SFTP-Foreign/
COMMENT=	SSH File Transfer Protocol client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/SFTP/Foreign/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
