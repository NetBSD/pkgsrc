# $NetBSD: Makefile,v 1.33 2013/12/09 14:17:41 obache Exp $

DISTNAME=	vicq-0.4.1
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq.old/
COMMENT=	Simple icq client written in perl
LICENSE=	gnu-gpl-v2

DEPENDS+=	{perl>=5.17.7,p5-Term-ReadLine>=1.11}:../../devel/p5-Term-ReadLine

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/vicq
CONFIGURE_DIRS=		Net/vICQ
TEST_TARGET=		# disabled

REPLACE_PERL=		vicq
PERL5_PACKLIST=		auto/Net/vICQ/.packlist

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/vicq

post-build:
	${PREFIX}/bin/pod2man ${WRKSRC}/vicq --section=1 \
	    --release="vICQ ${DISTNAME:C/.*-//}" \
	    --center="vICQ manual page" >  ${WRKSRC}/vicq.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${DESTDIR}${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicq.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
