# $NetBSD: Makefile,v 1.7 2013/05/31 12:39:40 wiz Exp $
#

DISTNAME=		dccserver-0.5
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://www.nih.at/dccserver/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/dccserver/
COMMENT=		Standalone replacement for the mIRC /dccserver command
LICENSE=		2-clause-bsd AND modified-bsd

GNU_CONFIGURE=		yes

# just a contrib script, don't want to incur a perl dependency for that
REPLACE_PERL=		contrib/dccsend.pl

SPECIAL_PERMS+=		${PREFIX}/bin/dccserver ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	share/dccserver

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/dccsend.pl ${DESTDIR}${PREFIX}/share/dccserver

.include "../../mk/bsd.pkg.mk"
