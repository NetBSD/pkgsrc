# $NetBSD: Makefile,v 1.12 2002/11/15 00:04:41 jlam Exp $

DISTNAME=	maildrop-1.3.9
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

PERL5_REQD=	5.6.0
USE_PERL5=	build
DEPENDS+=	courier-maildirmake>=0.37.1:../../mail/courier-maildirmake

USE_BUILDLINK2=	yes
USE_CXX=	yes

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

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
