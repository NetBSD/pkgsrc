# $NetBSD: Makefile,v 1.13 2001/02/25 04:17:39 hubertf Exp $
# FreeBSD Id: Makefile,v 1.15 1998/02/18 22:19:58 hoek Exp
#

DISTNAME=       uudeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

DEPENDS+=	uulib-0.5.13:../../converters/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--enable-inews=inews --disable-tcl
CONFIGURE_ENV=	LDFLAGS=-s

PORTDOCDIR=	${PREFIX}/share/doc/uudeview

post-install:
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${INSTALL_DATA_DIR} ${PORTDOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/HOWTO ${PORTDOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/porting.notes ${PORTDOCDIR}

.include "../../mk/bsd.pkg.mk"
