#!@perl@
#
# $NetBSD: hello_other.pl,v 1.1.1.1 2002/10/13 04:30:05 dmcmahill Exp $
#

use Parallel::Pvm;
use Sys::Hostname;
my $host = hostname();

$ptid = Parallel::Pvm::parent;
Parallel::Pvm::initsend(PvmDataDefault) ;
$buf=Parallel::Pvm::pack("Hi from hello_other.pl running on $host");
Parallel::Pvm::send($ptid,$buf);
Parallel::Pvm::exit;
exit 0;

