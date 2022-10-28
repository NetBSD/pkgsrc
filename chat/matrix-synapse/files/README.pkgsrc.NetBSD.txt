The builtin SQLite3 in NetBSD lacks features needed by Synapse.  To
use Synapse with SQLite3, one must build with pgksrc sqlite3, via
PREFER_PKGSRC+=sqlite3.
