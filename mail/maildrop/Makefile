# $NetBSD: Makefile,v 1.9.2.1 2002/06/23 18:51:29 jlam Exp $

DISTNAME=	maildrop-1.3.9
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

PERL5_REQD=	5.6.0
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=	courier-maildirmake>=0.37.1:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	yes

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

.include "../../mk/bsd.pkg.mk"
