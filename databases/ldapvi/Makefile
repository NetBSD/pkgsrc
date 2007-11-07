# $NetBSD: Makefile,v 1.2 2007/11/07 07:47:43 ghen Exp $

DISTNAME=		ldapvi-1.7
CATEGORIES=		databases
MASTER_SITES=		http://www.lichteblau.com/download/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.lichteblau.com/ldapvi/
COMMENT=		Interactive LDAP client

GNU_CONFIGURE=		yes
USE_NCURSES=		yes
USE_GNU_READLINE=	yes

USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		GNUmakefile

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapvi ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/ldapvi.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
