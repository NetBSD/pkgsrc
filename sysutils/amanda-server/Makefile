# $NetBSD: Makefile,v 1.54 2012/09/15 10:06:20 obache Exp $

PKGNAME=		amanda-server-${AMANDA_VERSION}
PKGREVISION=		1
SVR4_PKGNAME=		amase

COMMENT=		Server part of Amanda, a network backup system

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		awk:run mail:run

CONFIGURE_ENV+=		MAILER=${TOOLS_PATH.mail}
CONFIGURE_ARGS+=	--without-client --without-gnuplot

BUILD_DIRS=		device-src server-src changer-src

MANPAGES+=		amanda-devices.7
MANPAGES+=		amanda-compatibility.7
MANPAGES+=		amanda-changers.7
MANPAGES+=		amanda-interactivity.7
MANPAGES+=		amanda-taperscan.7
MANPAGES+=		amaddclient.8
MANPAGES+=		amadmin.8
MANPAGES+=		amaespipe.8
MANPAGES+=		amcheck.8
MANPAGES+=		amcheckdb.8
MANPAGES+=		amcheckdump.8
MANPAGES+=		amcleanup.8
MANPAGES+=		amcleanupdisk.8
MANPAGES+=		amcrypt-ossl-asym.8
MANPAGES+=		amcrypt-ossl.8
MANPAGES+=		amcrypt.8
MANPAGES+=		amcryptsimple.8
MANPAGES+=		amdevcheck.8
MANPAGES+=		amdump.8
MANPAGES+=		amflush.8
MANPAGES+=		amgetconf.8
MANPAGES+=		amgpgcrypt.8
MANPAGES+=		amlabel.8
MANPAGES+=		amoverview.8
MANPAGES+=		amreport.8
MANPAGES+=		amrmtape.8
MANPAGES+=		amserverconfig.8
MANPAGES+=		amstatus.8
MANPAGES+=		amtape.8
MANPAGES+=		amtapetype.8
MANPAGES+=		amtoc.8
MANPAGES+=		amvault.8
MANPAGES+=		disklist.5
MANPAGES+=		tapelist.5
MANPAGES+=		amrestore.8
MANPAGES+=		amfetchdump.8

PERL5_MODS+=		Amanda/Changer.pm
PERL5_MODS+=		Amanda/Changer/aggregate.pm
PERL5_MODS+=		Amanda/Changer/compat.pm
PERL5_MODS+=		Amanda/Changer/disk.pm
PERL5_MODS+=		Amanda/Changer/multi.pm
PERL5_MODS+=		Amanda/Changer/ndmp.pm
PERL5_MODS+=		Amanda/Changer/null.pm
PERL5_MODS+=		Amanda/Changer/rait.pm
PERL5_MODS+=		Amanda/Changer/robot.pm
PERL5_MODS+=		Amanda/Changer/single.pm
PERL5_MODS+=		Amanda/Cmdline.pm
PERL5_MODS+=		Amanda/Curinfo.pm
PERL5_MODS+=		Amanda/Curinfo/Info.pm
PERL5_MODS+=		Amanda/DB/Catalog.pm
PERL5_MODS+=		Amanda/Device.pm
PERL5_MODS+=		Amanda/Disklist.pm
PERL5_MODS+=		Amanda/Holding.pm
PERL5_MODS+=		Amanda/Interactivity.pm
PERL5_MODS+=		Amanda/Interactivity/email.pm
PERL5_MODS+=		Amanda/Interactivity/stdin.pm
PERL5_MODS+=		Amanda/Interactivity/tty.pm
PERL5_MODS+=		Amanda/Interactivity/tty_email.pm
PERL5_MODS+=		Amanda/Logfile.pm
PERL5_MODS+=		Amanda/Recovery/Clerk.pm
PERL5_MODS+=		Amanda/Recovery/Planner.pm
PERL5_MODS+=		Amanda/Recovery/Scan.pm
PERL5_MODS+=		Amanda/Report.pm
PERL5_MODS+=		Amanda/Report/human.pm
PERL5_MODS+=		Amanda/Report/postscript.pm
PERL5_MODS+=		Amanda/Report/xml.pm
PERL5_MODS+=		Amanda/ScanInventory.pm
PERL5_MODS+=		Amanda/Tapelist.pm
PERL5_MODS+=		Amanda/Taper/Controller.pm
PERL5_MODS+=		Amanda/Taper/Protocol.pm
PERL5_MODS+=		Amanda/Taper/Scan.pm
PERL5_MODS+=		Amanda/Taper/Scan/lexical.pm
PERL5_MODS+=		Amanda/Taper/Scan/oldest.pm
PERL5_MODS+=		Amanda/Taper/Scan/traditional.pm
PERL5_MODS+=		Amanda/Taper/Scribe.pm
PERL5_MODS+=		Amanda/Taper/Worker.pm
PERL5_MODS+=		Amanda/XferServer.pm

PERL5_LIBS+=		Cmdline
PERL5_LIBS+=		Device
PERL5_LIBS+=		Disklist
PERL5_LIBS+=		Logfile
PERL5_LIBS+=		Tapelist
PERL5_LIBS+=		XferServer

.include "../../sysutils/amanda-common/Makefile.common"

SPECIAL_PERMS+=		sbin/amcheck ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/planner ${AM_PROG_PERMS}
SPECIAL_PERMS+=		libexec/amanda/dumper ${AM_PROG_PERMS}

.include "../../sysutils/amanda-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
