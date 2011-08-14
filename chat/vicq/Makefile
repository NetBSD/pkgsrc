# $NetBSD: Makefile,v 1.28 2011/08/14 07:38:55 obache Exp $

DISTNAME=	vicq-0.4.1
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq.old/
COMMENT=	Simple icq client written in perl

DEPENDS+=	p5-Term-ReadLine>=1.11:../../devel/p5-Term-ReadLine

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/vicq/Net/vICQ
TEST_TARGET=		# disabled

REPLACE_PERL=		../../vicq
PERL5_PACKLIST=		auto/Net/vICQ/.packlist

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/vicq

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vicq/vicq ${DESTDIR}${PREFIX}/bin
	${PREFIX}/bin/pod2man ${WRKDIR}/vicq/vicq --section=1 \
	    --release="vICQ ${DISTNAME:C/.*-//}" \
	    --center="vICQ manual page" >  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vicq.1
	${INSTALL_DATA} ${WRKDIR}/vicq/vicqrc.example ${DESTDIR}${PREFIX}/share/examples/vicq

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
