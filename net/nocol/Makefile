# $NetBSD: Makefile,v 1.46 2018/08/22 09:45:55 wiz Exp $
#

DISTNAME=		nocol-4.3.1
PKGREVISION=		14
CATEGORIES=		net
MASTER_SITES=		http://www.netplex-tech.com/software/nocol/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.netplex-tech.com/software/nocol/
COMMENT=		Extensible network and system monitoring utility

MAKE_JOBS_SAFE=		no
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	< ${WRKSRC}/answers

USE_TOOLS+=		perl:run mkdirhier yacc
USE_LIBTOOL=		yes

INSTALL_TARGET=		install root

OWN_DIRS+=		/var/run/msgs
OWN_DIRS+=		/var/run/data

DEPENDS+=		tk-Tix-[0-9]*:../../x11/tk-Tix

.include "../../x11/tk/interpreter.mk"

REPLACE_PERL=		perlnocol/hostmon-osclients/hostmon-client*
REPLACE_WISH=		tknocol/tkNocol.tix

INSTALLATION_DIRS=	share/nocol/gifs
INSTALL_MAKE_FLAGS+=	ROOTDIR=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/mann \
			PIDDIR=${DESTDIR}/var/run \
			DATADIR=${DESTDIR}/var/run/data \
			MSGSDIR=${DESTDIR}/var/run/msgs

post-extract:
	${CP} ${FILESDIR}/answers ${WRKSRC}/answers

# XXX This is compiled in as the logging host. Compiling in "localhost"
# lacks a certain something; however, for years it was compiling in the
# name of the build host, or, not infrequently, something entirely
# invalid.
FQDN=			localhost

SUBST_CLASSES+=		answers
SUBST_STAGE.answers=	pre-configure
SUBST_FILES.answers=	answers
SUBST_VARS.answers=	PREFIX PKGMANDIR FQDN

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/cmu-snmp/snmp
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/cmu-snmp/snmpapps
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/cmu-snmp/snmp
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/cmu-snmp/snmpapps

post-install:
	set -e; for f in critical.wav error.wav warning.wav ; do	\
	    ${INSTALL_DATA} ${WRKSRC}/webnocol/$$f			\
			    ${DESTDIR}${PREFIX}/share/nocol;		\
	done

	set -e; for f in bluesq.gif critical.jpg empty.gif error.jpg	\
		greensq.gif help.jpg info.jpg redsq.gif warning.jpg	\
		yellowsq.gif ; do					\
	    ${INSTALL_DATA} ${WRKSRC}/webnocol/gifs/$$f			\
			    ${DESTDIR}${PREFIX}/share/nocol/gifs;	\
	done

.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
