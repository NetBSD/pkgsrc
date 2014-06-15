# $NetBSD: Makefile,v 1.8 2014/06/15 19:39:32 jnemeth Exp $

PKGNAME=	sendmail-cidrexpand-${DIST_VERS}
MAINTAINER=	hauke@NetBSD.org
COMMENT=	CIDR pre-parser for Sendmail access maps

PKG_OPTIONS=		# for the sake of Makefile.common
.include "../../mail/sendmail/Makefile.common"

DEPENDS+=		p5-Net-CIDR-[0-9]*:../../devel/p5-Net-CIDR

INSTALLATION_DIRS=	bin

REPLACE_PERL=		contrib/cidrexpand
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cidrexpand \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
