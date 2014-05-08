# $NetBSD: sites.mk,v 1.104 2014/05/08 11:11:15 ryoon Exp $
#
# This Makefile fragment defines read-only MASTER_SITE_* variables
# representing some well-known master distribution sites for software.
#

MASTER_SITE_XCONTRIB+=  \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://mirror.switch.ch/mirror/X11/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=       \
	http://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.funet.fi/pub/gnu/prep/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/gnu/ \
	ftp://ftp.dti.ad.jp/pub/GNU/ \
	ftp://mirrors.kernel.org/gnu/ \
	ftp://ftp.sunet.se/pub/gnu/ \
	ftp://ftp.lip6.fr/pub/gnu/ \
	http://gd.tuwien.ac.at/gnu/gnusrc/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/

MASTER_SITE_PERL_CPAN+= \
	ftp://cpan.pair.com/modules/by-module/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.gmd.de/mirrors/CPAN/modules/by-module/ \
	http://ftp.tuwien.ac.at/pub/CPAN/modules/by-module/ \
	http://cpan.perl.org/CPAN/modules/by-module/ \
	ftp://ftp.fi.muni.cz/pub/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	ftp://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://ftp.tex.ac.uk/tex-archive/ \
	ftp://ftp.dante.de/tex-archive/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/text/CTAN/ \
	http://www.dnsbalance.ring.gr.jp/archives/text/CTAN/

MASTER_SITE_SUNSITE+=   \
	ftp://sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/ \
	http://ftp.tuwien.ac.at/pub/linux/ibiblio/

MASTER_SITE_GNOME+=     \
	http://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/ \
	http://ftp.tuwien.ac.at/hci/gnome.org/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/ \
	ftp://ftp.dit.upm.es/linux/gnome/

MASTER_SITE_KDE+=	\
	ftp://ftp.kde.org/pub/kde/stable/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/X/kde/stable/ \
	http://www.dnsbalance.ring.gr.jp/archives/X/kde/stable/ \
	ftp://ftp.kddlabs.co.jp/pub/X/kde/stable/ \
	http://mirrors.isc.org/pub/kde/stable/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/kde/stable/ \
	ftp://kde.mirrors.tds.net/pub/kde/stable/ \
	http://gd.tuwien.ac.at/kde/stable/ \
	ftp://ftp.solnet.ch/mirror/KDE/stable/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/stable/ \
	ftp://mirrors.dotsrc.org/kde/stable/ \
	ftp://ftp.fi.muni.cz/pub/kde/stable/

MASTER_SITE_SOURCEFORGE+=	\
	http://downloads.sourceforge.net/sourceforge/

MASTER_SITE_SOURCEFORGE_JP+=	\
	http://jaist.dl.sourceforge.jp/ \
	http://iij.dl.sourceforge.jp/ \
	http://osdn.dl.sourceforge.jp/


MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr2.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/

MASTER_SITE_MOZILLA_ALL+=   \
	http://download-origin.cdn.mozilla.net/pub/mozilla.org/ \
	http://dm-download02.mozilla.org/pub/mozilla.org/ \
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/

# see http://www.mozilla.org/mirrors.html
MASTER_SITE_MOZILLA+=	\
	http://releases.mozilla.org/pub/mozilla.org/ \
	http://mirror.atlanticmetro.net/mozilla/ \
	ftp://releases.mozilla.org/pub/mozilla.org/ \
	http://mirror.yandex.ru/mozilla/ \
	http://ftp.cvut.cz/mozilla/ \
	http://ftp.heanet.ie/mirrors/ftp.mozilla.org/pub/mozilla.org/ \
	http://mozilla.mirror.ac.za/ \
	http://mirror.waia.asn.au/pub/mozilla/ \
	http://download-origin.cdn.mozilla.net/pub/mozilla.org/

# for Extended Support Release version
MASTER_SITE_MOZILLA_ESR+=	\
	http://download-origin.cdn.mozilla.net/pub/mozilla.org/ \
	http://dm-download02.mozilla.org/pub/mozilla.org/ \
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/ \
	ftp://ftp.pasteur.fr/pub/computing/xemacs/ \
	ftp://mirror.aarnet.edu.au/pub/xemacs/ \
	ftp://mirror.cict.fr/xemacs/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/text/xemacs/

MASTER_SITE_APACHE+=    \
	http://www.apache.org/dist/ \
	http://www.eu.apache.org/dist/ \
	http://apache.mirror.aussiehq.net.au/ \
	http://apache.oregonstate.edu/ \
	http://www.ibiblio.org/pub/mirrors/apache/ \
	http://mirror.nyi.net/apache/ \
	http://apache.mirrors.tds.net/ \
	http://ftp.unicamp.br/pub/apache/ \
	http://www.mirrorservice.org/sites/ftp.apache.org/ \
	http://www.meisei-u.ac.jp/mirror/apache/dist/ \
	http://ftp.twaren.net/Unix/Web/apache/ \
	http://ftp.cuhk.edu.hk/pub/packages/apache.org/ \
	ftp://ftp.oregonstate.edu/pub/apache/ \
	ftp://mirror.nyi.net/apache/ \
	ftp://apache.mirrors.tds.net/pub/apache.org/ \
	ftp://ftp.mirrorservice.org/sites/ftp.apache.org/ \
	http://gd.tuwien.ac.at/pub/infosys/servers/http/apache/dist/ \
	ftp://ftp.meisei-u.ac.jp/pub/www/apache/dist/ \
	ftp://ftp.twaren.net/Unix/Web/apache/

MASTER_SITE_MYSQL+=	\
	http://mysql.skynet.be/Downloads/ \
	ftp://ftp.mysql.skynet.be/pub/ftp.mysql.com/Downloads/ \
	http://mysql.mirror.kangaroot.net/Downloads/ \
	ftp://mysql.mirror.kangaroot.net/pub/mysql/Downloads/ \
	http://mysql.linux.cz/Downloads/ \
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/ \
	http://mirrors.dotsrc.org/mysql/Downloads/ \
	ftp://mirrors.dotsrc.org/mysql/Downloads/ \
	http://mysql.borsen.dk/Downloads/ \
	http://mirrors.ircam.fr/pub/mysql/Downloads/ \
	ftp://mirrors.ircam.fr/pub/mysql/Downloads/ \
	http://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	http://sunsite.informatik.rwth-aachen.de/mysql/Downloads/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/www.mysql.com/Downloads/ \
	ftp://ftp.fu-berlin.de/unix/databases/mysql/Downloads/ \
	http://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	http://mysql.mirrors.crysys.hit.bme.hu/Downloads/ \
	ftp://ftp.crysys.hu/pub/mysql/Downloads/ \
	http://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	ftp://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	http://na.mirror.garr.it/mirrors/MySQL/Downloads/ \
	http://mysql.proserve.nl/Downloads/ \
	http://mysql.nfsi.pt/Downloads/ \
	ftp://ftp.nfsi.pt/pub/mysql/Downloads/ \
	http://mirrors.xservers.ro/mysql/Downloads/ \
	http://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/ \
	ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/ \
	http://mysql.dataphone.se/Downloads/ \
	ftp://mirror2.dataphone.se/pub/mysql/Downloads/ \
	ftp://ftp.solnet.ch/mirror/mysql/Downloads/ \
	http://mirror.switch.ch/ftp/mirror/mysql/Downloads/ \
	ftp://mirror.switch.ch/mirror/mysql/Downloads/ \
	http://ftp.itu.edu.tr/Mirror/Mysql/Downloads/ \
	ftp://ftp.itu.edu.tr/Mirror/Mysql/Downloads/ \
	http://mysql.infocom.ua/Downloads/ \
	http://mirrors.dedipower.com/www.mysql.com/Downloads/ \
	http://www.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	ftp://ftp.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	http://mysql.mirror.rafal.ca/Downloads/ \
	ftp://mysql.mirror.rafal.ca/pub/mysql/Downloads/ \
	http://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	ftp://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	http://mirror.trouble-free.net/mysql_mirror/Downloads/ \
	http://mysql.llarian.net/Downloads/ \
	ftp://mysql.llarian.net/pub/mysql/Downloads/ \
	ftp://mirror.anl.gov/pub/mysql/Downloads/ \
	http://mirror.services.wisc.edu/mysql/Downloads/ \
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/ \
	http://mysql.he.net/Downloads/ \
	http://mysql.mirrors.arminco.com/Downloads/ \
	http://mysql.spd.co.il/Downloads/ \
	http://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	ftp://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	http://mysql.oss.eznetsols.org/Downloads/ \
	ftp://ftp.oss.eznetsols.org/mysql/Downloads/ \
	http://mysql.cs.pu.edu.tw/Downloads/ \
	http://mysql.ntu.edu.tw/Downloads/ \
	ftp://ftp.ntu.edu.tw/pub/MySQL/Downloads/ \
	http://mysql.cdpa.nsysu.edu.tw/Downloads/ \
	ftp://mysql.cdpa.nsysu.edu.tw/Unix/Database/MySQL/Downloads/ \
	http://mirror-fpt-telecom.fpt.net/mysql/Downloads/ \
	http://mysql.mirror.ac.za/Downloads/ \
	http://mysql.inspire.net.nz/Downloads/ \
	ftp://mysql.inspire.net.nz/mysql/Downloads/

MASTER_SITE_DEBIAN+= \
	http://ftp.debian.org/debian/ \
	http://ftp.at.debian.org/debian/ \
	http://ftp.au.debian.org/debian/ \
	http://ftp.wa.au.debian.org/debian/ \
	http://ftp.bg.debian.org/debian/ \
	http://ftp.cl.debian.org/debian/ \
	http://ftp.cz.debian.org/debian/ \
	http://ftp.de.debian.org/debian/ \
	http://ftp2.de.debian.org/debian/ \
	http://ftp.ee.debian.org/debian/ \
	http://ftp.fi.debian.org/debian/ \
	http://ftp.fr.debian.org/debian/ \
	http://ftp2.fr.debian.org/debian/ \
	http://ftp.uk.debian.org/debian/ \
	http://ftp.hr.debian.org/debian/ \
	http://ftp.ie.debian.org/debian/ \
	http://ftp.is.debian.org/debian/ \
	http://ftp.it.debian.org/debian/ \
	http://ftp.jp.debian.org/debian/ \
	http://ftp.nl.debian.org/debian/ \
	http://ftp.no.debian.org/debian/ \
	http://ftp.nz.debian.org/debian/ \
	http://ftp.pl.debian.org/debian/ \
	http://ftp.ru.debian.org/debian/ \
	http://ftp.se.debian.org/debian/ \
	http://ftp.sk.debian.org/debian/ \
	http://ftp.us.debian.org/debian/

MASTER_SITE_OPENOFFICE+=	\
	http://mirrors.isc.org/pub/openoffice/ \
	http://openoffice.mirrors.ilisys.com.au/ \
	http://www.ibiblio.org/pub/mirrors/openoffice/ \
	ftp://ftp.ussg.iu.edu/pub/openoffice/ \
	http://gd.tuwien.ac.at/office/openoffice/ \
	http://ftp.sh.cvut.cz/MIRRORS/OpenOffice/ \
	ftp://ftp.funet.fi/pub/mirrors/openoffice.org/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/OpenOffice/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/ \
	ftp://ftp.join.uni-muenster.de/pub/software/OpenOffice/ \
	http://ftp.ntua.gr/pub/OpenOffice/ \
	http://ftp.rhnet.is/pub/OpenOffice/ \
	http://na.mirror.garr.it/mirrors/openoffice/ \
	http://vlaai.snt.utwente.nl/pub/software/openoffice/ \
	http://niihau.student.utwente.nl/openoffice/ \
	http://borft.student.utwente.nl/openoffice/ \
	http://ftp.iasi.roedu.net/mirrors/openoffice.org/ \
	ftp://ftp.arnes.si/packages/OpenOffice.org/ \
	ftp://ftp.saix.net/pub/OpenOffice.org/ \
	http://ftp.sunet.se/pub/Office/OpenOffice.org/ \
	ftp://mirror.switch.ch/mirror/OpenOffice/ \
	http://komo.vlsm.org/openoffice/ \
	ftp://ftp.kddlabs.co.jp/office/openoffice/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/misc/openoffice/ \
	ftp://ftp.kr.freebsd.org/pub/openoffice/

MASTER_SITE_CYGWIN+= \
	http://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	http://mirrors.xmission.com/cygwin/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/pc/gnu-win32/ \
	ftp://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/ \
	http://ifarchive.heanet.ie/if-archive/ \
	ftp://ftp.giga.or.at/pub/ifarchive/

### PGSQL list was last updated on 20110328
MASTER_SITE_PGSQL+=	\
	ftp://ftp5.ca.postgresql.org/mirrors/postgresql/ \
	http://ftp2.cz.postgresql.org/pub/postgresql/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/ \
	http://ftp.dk.postgresql.org/postgresql/ \
	ftp://ftp.dk.postgresql.org/postgresql/ \
	http://ftp.ee.postgresql.org/pub/postgresql/ \
	ftp://ftp.fi.postgresql.org/pub/postgresql/ \
	http://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	http://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	http://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	ftp://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	ftp://ftp7.de.postgresql.org/pub/ftp.postgresql.org/ \
	ftp://ftp9.de.postgresql.org/unix/databases/postgresql/ \
	http://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	http://ftp3.gr.postgresql.org/ \
	ftp://ftp3.gr.postgresql.org/mirrors/postgresql/ \
	http://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	http://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	ftp://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	http://ftp2.it.postgresql.org/mirrors/postgres/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/ \
	ftp://ftp3.jp.postgresql.org/pub/db/postgresql/ \
	ftp://ftp.lv.postgresql.org/mirrors/ftp.postgresql.org/ \
	http://ftp2.nl.postgresql.org/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/ \
	ftp://ftp.nz.postgresql.org/postgresql/ \
	http://ftp6.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/ \
	http://ftp8.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp8.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/ \
	http://ftp.pt.postgresql.org/pub/postgresql/ \
	ftp://ftp.pt.postgresql.org/pub/postgresql/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/ \
	ftp://ftp.si.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.za.postgresql.org/mirror/ftp.postgresql.org/ \
	http://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	http://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.ch.postgresql.org/mirror/postgresql/ \
	http://ftp3.tw.postgresql.org/postgresql/ \
	ftp://ftp3.tw.postgresql.org/postgresql/ \
	ftp://ftp5.us.postgresql.org/pub/PostgreSQL/ \
	http://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/ \
	ftp://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/

MASTER_SITE_GENTOO+= \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/gentoo/ \
	http://ftp.heanet.ie/pub/gentoo/ \
	http://mirror.bytemark.co.uk/gentoo/ \
	http://mirror.switch.ch/ftp/mirror/gentoo/ \
	http://gentoo.mirror.dkm.cz/pub/gentoo/ \
	http://ftp.ds.karen.hj.se/gentoo/ \
	ftp://ftp.free.fr/mirrors/ftp.gentoo.org/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/ \
	http://darkstar.ist.utl.pt/gentoo/ \
	http://gentoo-euetib.upc.es/mirror/gentoo/ \
	http://ftp.ntua.gr/pub/linux/gentoo/ \
	http://www.las.ic.unicamp.br/pub/gentoo/ \
	http://mirror.yandex.ru/gentoo-distfiles/ \
	http://ftp.swin.edu.au/gentoo/ \
	http://ftp.iij.ad.jp/pub/linux/gentoo/ \
	http://ftp.jaist.ac.jp/pub/Linux/Gentoo/ \
	http://ftp.cs.pu.edu.tw/Linux/Gentoo/ \
	http://distfiles.gentoo.org/

MASTER_SITE_XORG+= \
	http://xorg.freedesktop.org/releases/individual/ \
	ftp://ftp.x.org/pub/individual/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/individual/

MASTER_SITE_FREEBSD+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/

MASTER_SITE_NETLIB+= \
	http://netlib.org/ \
	http://netlib.sandia.gov/ \
	http://www.netlib.no/netlib/ \
	http://www.mirrorservice.org/sites/netlib.bell-labs.com/netlib/

MASTER_SITE_RUBYGEMS+= \
	http://rubygems.org/gems/ \
	http://gems.rubyforge.org/gems/

MASTER_SITE_HASKELL_HACKAGE+=	\
	http://hackage.haskell.org/package/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.fi.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/ \
	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/
