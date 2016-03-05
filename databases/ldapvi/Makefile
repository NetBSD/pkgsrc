# $NetBSD: Makefile,v 1.20 2016/03/05 11:28:11 jperkin Exp $

DISTNAME=		ldapvi-1.7
PKGREVISION=		13
CATEGORIES=		databases
MASTER_SITES=		http://www.lichteblau.com/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lichteblau.com/ldapvi/
COMMENT=		Interactive LDAP client

GNU_CONFIGURE=		yes
USE_NCURSES=		yes

USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		GNUmakefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapvi ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/ldapvi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
