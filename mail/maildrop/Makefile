# $NetBSD: Makefile,v 1.8 2002/02/03 13:38:39 jlam Exp $

DISTNAME=	maildrop-1.3.7
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

PERL5_REQD=	5.6.0
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=	courier-maildirmake>=0.37.1:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	yes

.include "../../mail/courier-auth/Makefile.common"

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-userdb

.if defined(STRIPFLAG) && !empty(STRIPFLAG:M-s)
INSTALL_TARGET=		install-strip
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}/README.maildrop
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildroptips.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
