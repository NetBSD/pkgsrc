# $NetBSD: Makefile,v 1.45 2001/05/16 08:35:10 abs Exp $
# FreeBSD Id: Makefile,v 1.21 1997/03/26 02:12:07 ache Exp
#

DISTNAME=       pine4.33
PKGNAME=        pine-4.33
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Program for Internet E-mail and News

BUILD_DEFS+=	PINE_USE_LDAP

# This pkg doesn't build pico or libpico; the pico pkg does that part.
DEPENDS+=	pico-4.0:../../editors/pico
DEPENDS+=	imap-uw>=2000.0.3:../../mail/imap-uw

.include "../../mk/bsd.prefs.mk"

.if defined(PINE_USE_LDAP) && ${PINE_USE_LDAP} == YES
DEPENDS+=      openldap-*:../../databases/openldap
LDAPCFLAGS=    LDAPCFLAGS="-DENABLE_LDAP -I${PREFIX}/include"
LDAPLIBS=      LDAPLIBS="-lldap -llber"
.endif

USE_LIBTOOL=	yes
USE_SSL=	yes
CONFIGURE_ENV+=	LT=${LIBTOOL}
MAKE_ENV+=	LT=${LIBTOOL}

pre-patch:
	# Make sure the imap lib that comes with pine isn't
	# used (see http://www.securityfocus.com/advisories/2646)
	${RM} -fr ${WRKSRC}/imap

do-configure:
	${CP} -f ${WRKSRC}/pine/osdep/os-neb.h ${WRKSRC}/pine/osdep/os-neb.h.orig
	${SED} \
		-e 's@/usr/local/lib/@${PREFIX}/etc/@' \
		<${WRKSRC}/pine/osdep/os-neb.h.orig >${WRKSRC}/pine/osdep/os-neb.h
	@${RM} -rf ${WRKSRC}/pico
	@${LN} -sf ${LOCALBASE}/include/pico ${WRKSRC}/pico

do-build:
	cd ${WRKSRC} && ./build ${BUILDNAME} ${LDAPCFLAGS} ${LDAPLIBS} PREFIX=${PREFIX}

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/pine/pine ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pine
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.pgp.sample ${PREFIX}/share/examples/pine/dot.pinerc.pgp
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/share/examples/pine/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/share/examples/pine/
	@[ -f ${PREFIX}/etc/pine.conf ] || ${CP} ${PREFIX}/share/examples/pine/pine.conf ${PREFIX}/etc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib/utils
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/pine/
	${INSTALL_DATA} ${WRKSRC}/contrib/krb5-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/ldap-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/utils/* ${PREFIX}/share/pine/contrib/utils

.include "../../mk/bsd.pkg.mk"
.if ${OPSYS} == "SunOS"
BUILDNAME= gs5
.else
BUILDNAME= neb
.endif
