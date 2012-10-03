# $NetBSD: Makefile,v 1.23 2012/10/03 21:57:46 wiz Exp $
#

DISTNAME=		cdif-1.19
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://ftp.freebsd.org/pub/FreeBSD/distfiles/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.srekcah.org/~utashiro/perl/scripts/cdif/
COMMENT=		Word context diff
#LICENSE=		cdif-license # 1.19 can be used for any porpose

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_BULK_PLATFORM=	HPUX-*-*

WRKSRC=			${WRKDIR}
USE_TOOLS+=		perl:run

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

REPLACE_PERL=		${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
