# $NetBSD: Makefile,v 1.4 2009/02/15 18:49:54 wiz Exp $
#

DISTNAME=		dccserver-0.4
CATEGORIES=		chat
MASTER_SITES=		http://www.nih.at/dccserver/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/dccserver/
COMMENT=		Standalone replacement for the mIRC /dccserver command

GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir
# just a contrib script, don't want to incur a perl dependency for that
REPLACE_PERL=		contrib/dccsend.pl

SPECIAL_PERMS+=		${PREFIX}/bin/dccserver ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/dccserver
	${INSTALL_DATA} ${WRKSRC}/contrib/dccsend.pl ${DESTDIR}${PREFIX}/share/dccserver

.include "../../mk/bsd.pkg.mk"
