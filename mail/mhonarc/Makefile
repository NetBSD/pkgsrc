# $NetBSD: Makefile,v 1.38.4.1 2015/10/02 19:49:13 bsiegert Exp $

DISTNAME=	MHonArc-2.6.19
PKGNAME=	mhonarc-2.6.19
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.mhonarc.org/release/MHonArc/tar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/
COMMENT=	Mailbox to HTML converter, suitable for list archives
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
NO_BUILD=	YES

INSTALLATION_DIRS=	bin lib man share/doc

.include "../../mk/bsd.prefs.mk"

MY_INSTALL_FLAGS=	-prefix ${PREFIX}
MY_INSTALL_FLAGS+=	-perl ${PERL5}
MY_INSTALL_FLAGS+=	-binpath ${PREFIX}/bin
MY_INSTALL_FLAGS+=	-libpath ${PREFIX}/lib/mhonarc
MY_INSTALL_FLAGS+=	-docpath ${PREFIX}/share/doc/mhonarc
MY_INSTALL_FLAGS+=	-manpath ${PREFIX}/${PKGMANDIR}
.if defined(_USE_DESTDIR) && ${_USE_DESTDIR} != "no"
MY_INSTALL_FLAGS+=	-root ${DESTDIR}
.endif
MY_INSTALL_FLAGS+=	-batch

do-install:
	cd ${WRKSRC} && ${PERL5} ./install.me ${MY_INSTALL_FLAGS}

.include "../../mk/bsd.pkg.mk"
