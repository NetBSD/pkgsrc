# $NetBSD: Makefile,v 1.16 2004/03/10 11:35:47 markd Exp $

DISTNAME=	maildrop-1.3.9
EXTRACT_SUFX=	.tar.gz
COMMENT=	Courier mail delivery agent with filtering abilities
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

PERL5_REQD+=	5.6.0
USE_PERL5=	build
DEPENDS+=	courier-maildirmake>=0.37.1:../../mail/courier-maildirmake

USE_BUILDLINK2=	yes
USE_DB185=	yes
USE_LANGUAGES=	yes

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

.include "../../databases/db/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
