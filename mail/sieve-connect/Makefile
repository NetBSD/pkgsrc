# $NetBSD: Makefile,v 1.2 2019/08/11 13:21:41 wiz Exp $
#

DISTNAME=		sieve-connect-0.89
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		https://people.spodhuis.org/phil.pennock/software/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/philpennock/sieve-connect
COMMENT=		Command line client for the ManageSieve protocol
LICENSE=		modified-bsd

USE_TOOLS+=		sed chmod rm perl

BUILD_MAKE_FLAGS+=	PERL5BIN=${PERL5:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} MANDIR=${PKGMANDIR}

DEPENDS+=		p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=		p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=		p5-IO-Socket-SSL>=1.14:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-Pod-Usage-[0-9]*:../../devel/p5-Pod-Usage

# optional
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
#DEPENDS+=		p5-Mozilla-PublicSuffix-[0-9]*:../../???/p5-Mozilla-PublicSuffix
#DEPENDS+=		p5-Term-ReadLine-Gnu-[0-9]*:../../???/p5-Term-ReadLine-Gnu

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
