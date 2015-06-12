# $NetBSD: Makefile,v 1.28 2015/06/12 10:51:19 wiz Exp $
#

DISTNAME=		cdif-1.19
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		http://ftp.freebsd.org/pub/FreeBSD/distfiles/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.srekcah.org/~utashiro/perl/scripts/cdif/
COMMENT=		Word context diff
#LICENSE=		cdif-license # 1.19 can be used for any porpose

WRKSRC=			${WRKDIR}
USE_TOOLS+=		perl:run

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

REPLACE_PERL=		${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
