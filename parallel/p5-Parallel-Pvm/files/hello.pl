#!@perl@
#
# $NetBSD: hello.pl,v 1.1.1.1 2002/10/13 04:30:05 dmcmahill Exp $
#

use Parallel::Pvm;
use File::Basename;

$mytid = Parallel::Pvm::mytid ;
printf "My task ID is %x\n", $mytid;

# spawn 1 copy of "hello_other"
$cmd="@exampledir@/hello_other.pl";

($ntask, @tids) = Parallel::Pvm::spawn($cmd, 1);
print "ntask = $ntask\n";
print "tids  = @tids\n";

if ($ntask == 1) {
	# receive a message from the task we have spawned
	$bufid=Parallel::Pvm::recv();

	if ($bufid >= 0) {
		($info,$bytes,$tag,$stid) = Parallel::Pvm::bufinfo($bufid) ;
		print "info  = $info\n";
		print "bytes = $bytes\n";
		print "tag   = $tag\n";
		printf "stid  = %x\n",$stid;
		$str = Parallel::Pvm::unpack;
		printf "from t%x: \"%s\"\n",$stid,$str;
        	} 
} else {
	printf "can't start hello_other\n";
}	

Parallel::Pvm::exit();


