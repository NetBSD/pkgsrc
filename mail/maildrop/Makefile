# $NetBSD: Makefile,v 1.21 2004/11/15 17:54:49 jlam Exp $

DISTNAME=	maildrop-1.3.9
PKGREVISION=	2
EXTRACT_SUFX=	.tar.gz
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

PERL5_REQD+=	5.6.0
USE_PERL5=	build
DEPENDS+=	courier-maildir>=0.45.6:../../mail/courier-maildir

USE_BUILDLINK3=	yes
USE_DB185=	yes
BDB_ACCEPTED=	db2
USE_LANGUAGES=	c c++

.include "../../mail/courier-auth/Makefile.common"

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-userdb

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=		install-strip
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}/README.maildrop
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildroptips.txt ${DOCDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
