# $NetBSD: Makefile,v 1.9 1998/08/20 15:16:43 tsarna Exp $
# FreeBSD Id: Makefile,v 1.15 1998/02/18 22:19:58 hoek Exp
#

DISTNAME=       uudeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/

DEPENDS+=	uulib-0.5.13:../../converters/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--enable-inews=inews --disable-tcl
CONFIGURE_ENV=	LDFLAGS=-s

PORTDOCDIR?=	share/doc/uudeview

.include "../../mk/bsd.prefs.mk"

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${WRKSRC}/HOWTO ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/${PORTDOCDIR}
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif

.include "../../mk/bsd.pkg.mk"
