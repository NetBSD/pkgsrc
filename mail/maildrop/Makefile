# $NetBSD: Makefile,v 1.5 2001/08/16 07:39:21 jlam Exp $
#

DISTNAME=	maildrop-1.3.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/
COMMENT=	mail delivery agent with filtering abilities

PERL5_REQD=	5.6.0
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
DEPENDS+=	courier-maildirmake-[0-9]*:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-db=db
CONFIGURE_ARGS+=	--with-etcdir=/etc

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/db2
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/maildrop
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/maildrop
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${PREFIX}/share/doc/maildrop

.include "../../mk/bsd.pkg.mk"
